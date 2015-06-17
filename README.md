# phigital-ios-sampleapp

Phigital has built a turnkey platform to engage consumers with mobile experiences that use a mix of locations, actions, and rich media to drive purchase behavior and brand loyalty.<br />We do it faster, cheaper, and at scale.

# How To Get your Phigital Application Identifier, Application Secret and Deeplink Protocol

- Go To   https://demo.gophigital.com.
- Sign Up to create your account.
- Go To ADMIN.
- Go To App.
- Tap NEW APP.
- Fill in the fields at the form that appears and Save.
- You should see your APP ID, CLIENT SECRET and DEEPLINK PROTOCOL.


# How To Download PhigitalSDK

Download PhigitalSDK from  https://s3.amazonaws.com/cocoapodbinaries/sdk/release/latest/PhigitalSDK.zip .

Drag and drop PhigitalSDK into your project. 


# Installation with CocoaPods


Step 1: Download CocoaPods<br />
CocoaPods is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like Phigital in your projects.
CocoaPods is distributed as a ruby gem and is installed by running the following commands in Terminal.app:<br /><br />
$ sudo gem install cocoapods<br />
$ pod setup<br /><br />

Depending on your Ruby installation, you may not have to run as sudo to install the cocoapods gem.<br />

Step 2: Create a Podfile<br />
Project dependencies to be managed by CocoaPods are specified in a file called Podfile. Create this file in the same directory as your Xcode project (.xcodeproj) file:<br /><br />
$ touch Podfile<br />
$ open -e Podfile<br /><br />
TextEdit should open up showing an empty file. You just created the pod file and opened it! Ready to add some content to the empty pod file?
Copy and paste the following lines into the TextEdit window:<br />

source 'https://github.com/CocoaPods/specs.git'

pod 'Phigital', '> 2.0.0'<br />

Make sure the quotes are straight, not slanted/apostrophes. If TextEdit gives you trouble, use Sublime or copy/paste the code above instead of typing it in.<br /><br />

Step 3: Install Dependencies<br />
Now you can install the dependencies in your project:<br /><br />
$ pod install<br /><br />
From now on, be sure to always open the generated Xcode workspace (.xcworkspace) instead of the project file when building your project:<br /><br />
$ open <YourProjectName>.xcworkspace<br /><br />


# Setup XCode Project

- Go To Targets -> General -> Embedded Binaries : Add PhigitalSDK.framework either from Pods folder of your project (if using Pods Go To (yourPROJECT_DIR) -> Pods -> Phigital -> PhigitalSDK) or from PhigitalSDK folder (if installed PhigitalSDK manually).

- Add “Required background modes” key to your project’s info.plist and enable audio, bluetooth, network downloading and location services.


# How to Get Started with phigitalSample Application


- Add your appId and appSecret provided by Phigital at AppDelegate.

- Add your Email and Password at relevant text fields.

- Add URL Scheme (Deeplink Protocol) provided by Phigital to your project’s info.plist.

  URL types -> Item 0 -> URL Schemes -> Item 0 add YourDeeplinkProtocol.

- Get your experienceId by navigating to https://demo.gophigital.com<br />-> Go To Sign In<br />-> Go To CREATE<br />-> Choose an experience (or create one if you haven't any)<br />->
Go To Share<br />-> Get your experienceId from https://demo.gophigital.com/experienceId link (example of experienceId : expTUSRjNhL).

- Add your experienceId at phigitalStartExperience method at ViewController.m.


# More Info

For extra info you may refer to Documentation included in PhigitalSDKResources.
 

