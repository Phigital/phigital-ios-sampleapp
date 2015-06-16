# phigital-ios-sampleapp
Phigital iOS Sample App


- Get your Phigital Application Identifier, Application Secret and Deeplink Protocol.

Go To   https://demo.gophigital.com.
Sign Up to create your account.
Go To ADMIN -> App.
Tap NEW APP.
Fill in the fields at the form that appears and Save.
You should see your APP ID, CLIENT SECRET and DEEPLINK PROTOCOL.

- Open Xcode project.

- Install PhigitalSDK.


Option 1:  

Download PhigitalSDK from  https://s3.amazonaws.com/cocoapodbinaries/sdk/release/latest/PhigitalSDK.zip .

Drag and drop PhigitalSDK into your project. 



OR 

Option 2:

Download using CocoaPods

Step 1: Download CocoaPods
CocoaPods is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like Phigital in your projects.
CocoaPods is distributed as a ruby gem, and is installed by running the following commands in Terminal.app:
$ sudo gem install cocoapods
$ pod setup
Depending on your Ruby installation, you may not have to run as sudo to install the cocoapods gem.

Step 2: Create a Podfile
Project dependencies to be managed by CocoaPods are specified in a file called Podfile. Create this file in the same directory as your Xcode project (.xcodeproj) file:
$ touch Podfile
$ open -e Podfile
TextEdit should open up showing an empty file. You just created the pod file and opened it! Ready to add some content to the empty pod file?
Copy and paste the following lines into the TextEdit window:

source 'https://github.com/CocoaPods/specs.git'

pod 'Phigital', '> 2.0.0'

Make sure the quotes are straight, not slanted/apostrophes. If TextEdit gives you trouble, use Sublime or copy/paste the code above instead of typing it in.

Step 3: Install Dependencies
Now you can install the dependencies in your project:
$ pod install
From now on, be sure to always open the generated Xcode workspace (.xcworkspace) instead of the project file when building your project:
$ open <YourProjectName>.xcworkspace


- Go To Targets -> General -> Embedded Binaries : Delete PhigitalSDK.framework, Press (+) and add PhigitalSDK.framework .


- Add URL Scheme (Deeplink Protocol) provided by Phigital (step 1) to your project’s info.plist .

URL types -> Item 0 -> URL Schemes -> Item 0 add YourDeeplinkProtocol .


- Add “Required background modes” key to your project’s info.plist with following itms to enable audio, bluetooth, network downloading and location services.



- Add  #import PhigitalSDK/Phigital.h to your class.


- Add PhigitalProtocol at AppDelegate.


- Download Phigital Resources from https://s3.amazonaws.com/cocoapodbinaries/sdk/release/latest/PhigitalSDK.zip. 
Unzip to get PhigitalSDKResources.
Drag and drop the folder into your project.

- Add your appId and appSecret at AppDelegate.

- Get your experienceId by navigating to https://demo.gophigital.com -> GoTo Sign In -> GoTo CREATE -> Choose an experience (or create one if you haven't any) ->
GoTo Share -> Get your experienceId from https://demo.gophigital.com/experienceId link (example of experienceId : expTUSRjNhL).

- Add your experienceId at phigitalStartExperience method at ViewController.m .

- Add your Email and PWD at relevant text fields. 

