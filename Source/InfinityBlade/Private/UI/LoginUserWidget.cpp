// Fill out your copyright notice in the Description page of Project Settings.

#include "LoginUserWidget.h"



////控件创建完成后初始化方法
bool ULoginUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//初始化返回按钮
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	//初始化登陆按钮
	LoginBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));	
	//初始化加载框
	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("Loading")));
	//初始化账号输入框
	NicknameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("Input_Nickname")));
	//初始化密码输入框
	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("Input_Password")));
	//初始化信息提示框
	MessageWidget = Cast<UMessageUserWidget>(GetWidgetFromName(TEXT("BP_MessageWidget")));
	//初始化登陆按钮点击事件
	LoginBtn->OnClicked.AddDynamic(this, &ULoginUserWidget::LoginBtnOnClickedEvent);

	return true;
}
//登陆界面--登陆按钮点击事件
void ULoginUserWidget::LoginBtnOnClickedEvent()
{
	//获取昵称,密码
	FString Nickname = NicknameInput->GetText().ToString();
	FString Password = PasswordInput->GetText().ToString();
	//判断昵称是否合法（2-6）
	if (Nickname.Len() < 2 || Nickname.Len() > 6)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow, TEXT("昵称长度不合法..."));
		MessageWidget->ShowTipEvent(TEXT("昵称长度不合法..."));
		return;
	}
	if (Password.IsEmpty())
	{
		MessageWidget->ShowTipEvent(TEXT("密码不能为空..."));
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow, Nickname + "--" + Password);
	//显示加载框
	CircularThrobber->SetVisibility(ESlateVisibility::Visible);
	//设置注册按钮不可用
	LoginBtn->SetIsEnabled(false);
	//注册界面--账号登陆方法
	AccountRegisterFromServer(Nickname, Password);
}

//登陆界面--账号登陆方法
void ULoginUserWidget::AccountRegisterFromServer(FString& Nickname, FString& Password)
{
	//创建要提交的Json字符串
	FString RegisterInfo;
	//创建共享Json写入器
	TSharedRef <TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	//开始写入数据
	JsonWriter->WriteObjectStart();
	//写入昵称,秘密
	JsonWriter->WriteValue("nickname", Nickname);
	JsonWriter->WriteValue("password", Password);
	//关闭Json写入
	JsonWriter->WriteObjectEnd();
	//关闭Json写入器
	JsonWriter->Close();
	GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow, RegisterInfo);

	//创建HTTP请求
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	//设置请求方式
	HttpRequest->SetVerb("POST");
	//设置请求头
	HttpRequest->SetHeader("Content-Type", "application/json;charset=utf-8");
	//设置请求的url
	HttpRequest->SetURL("http://192.168.50.35:7900/user/login-user");
	//设置上传的数据
	HttpRequest->SetContentAsString(RegisterInfo);
	//设置请求成功后委托方法
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &ULoginUserWidget::RequestComplete);
	//请求服务器
	HttpRequest->ProcessRequest();
}
//请求响应方法
void ULoginUserWidget::RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{
	//隐藏加载框
	CircularThrobber->SetVisibility(ESlateVisibility::Hidden);
	//启用注册按钮
	LoginBtn->SetIsEnabled(true);
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
		//获取返回数据的msg
		FString Msg = JsonObject->GetStringField("msg");
		//获取返回数据的data
		TSharedPtr<FJsonObject> JsonData = JsonObject->GetObjectField("data");
		FString Id = JsonData->GetStringField("id");
		FString Nickname = JsonData->GetStringField("nickname");
		
		
		
		
		GEngine->AddOnScreenDebugMessage(-1, 3.5f, FColor::Yellow, Msg);
	

		if (!Nickname.IsEmpty())
		{
			//切换关卡
			MessageWidget->ShowTipEvent(Msg);
			UCustomGameInstance* GameInstance = Cast<UCustomGameInstance>(GetWorld()->GetGameInstance());
			GameInstance->ContextMap.Add("id", Id);
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Map/Map_Main"));
		}
		else 
		{
			MessageWidget->ShowTipEvent(Msg);
			
		}

	}
}
