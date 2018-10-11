// Fill out your copyright notice in the Description page of Project Settings.

#include "RegisterUserWidget.h"

//控件创建完成后初始化方法
bool URegisterUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//注册界面--返回按钮
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	//初始化加载框
	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("Loading")));
	//注册界面--账号输入框
	NicknameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("Input_Nickname")));
	//注册界面--密码输入框
	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("Input_Password")));
	//注册界面--重复密码输入框
	RePasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("Input_RePassword")));
	//注册界面--注册按钮
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	//注册界面--注册按钮点击事件
	RegisterBtn->OnClicked.AddDynamic(this, &URegisterUserWidget::RegisterBtnOnClickedEvent);
	//初始化信息提示框
	MessageWidget = Cast<UMessageUserWidget>(GetWidgetFromName(TEXT("BP_MessageWidget")));
	


	return true;
}
//注册界面--注册按钮点击事件
void URegisterUserWidget::RegisterBtnOnClickedEvent()
{
	//获取昵称,密码
	FString Nickname = NicknameInput->GetText().ToString();
	FString Password = PasswordInput->GetText().ToString();
	FString RePassword = RePasswordInput->GetText().ToString();
	//判断昵称是否合法（2-6）
	if (Nickname.Len()<2||Nickname.Len()>6)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow, TEXT("昵称长度不合法..."));
		MessageWidget->ShowTipEvent(TEXT("昵称长度不合法..."));
		return;
	}
	//两次输入的密码是否一致
	if (!Password.Equals(RePassword))
	{
		FString Tip = L"两次输入密码不一致...";
		GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow, Tip);
		MessageWidget->ShowTipEvent(Tip);
		return;
	}
	GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow, Nickname +"--"+ Password);
	//显示加载框
	CircularThrobber->SetVisibility(ESlateVisibility::Visible);
	//设置注册按钮不可用
	RegisterBtn->SetIsEnabled(false);
	//注册界面--账号注册方法
	AccountRegisterFromServer(Nickname, Password);


}

//注册界面--账号注册方法
void URegisterUserWidget::AccountRegisterFromServer(FString& Nickname, FString& Password)
{
	//创建要提交的Json字符串
	FString RegisterInfo;
	//创建共享Json写入器
	TSharedRef <TJsonWriter<TCHAR,TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter= TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	//开始写入数据
	JsonWriter->WriteObjectStart();
	//写入昵称,秘密
	JsonWriter->WriteValue("nickname", Nickname);
	JsonWriter->WriteValue("password",Password);
	//关闭Json写入
	JsonWriter->WriteObjectEnd();
	//关闭Json写入器
	JsonWriter->Close();
	GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow,RegisterInfo);

	//创建HTTP请求
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	//设置请求方式
	HttpRequest->SetVerb("POST");
	//设置请求头
	HttpRequest->SetHeader("Content-Type", "application/json;charset=utf-8");
	//设置请求的url
	HttpRequest->SetURL("http://192.168.50.35:7900/user/register-user");
	//设置上传的数据
	HttpRequest->SetContentAsString(RegisterInfo);
	//设置请求成功后委托方法
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &URegisterUserWidget::RequestComplete);
	//请求服务器
	HttpRequest->ProcessRequest();
}

//请求响应方法
void URegisterUserWidget::RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{
	//隐藏加载框
	CircularThrobber->SetVisibility(ESlateVisibility::Hidden);
	//启用注册按钮
	RegisterBtn->SetIsEnabled(true);
	//判断响应状态是否正常
	if (!EHttpResponseCodes::IsOk(ResponsePtr->GetResponseCode()))
	{
		return;
	}
	//获取返回的值
	FString Data = ResponsePtr->GetContentAsString();
	//创建一个Json对象
	TSharedPtr<FJsonObject> JsonObject;
	//创建Json解析器
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Data);
	//Json反序列化
	bool bIsParse = FJsonSerializer::Deserialize(JsonReader, JsonObject);
	//判断是否解析成功
	if (bIsParse)
	{
		FString Status = JsonObject->GetStringField("status");
		FString Msg = JsonObject->GetStringField("msg");
		GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow, Status);
		MessageWidget->ShowTipEvent(Msg);

	}


}
