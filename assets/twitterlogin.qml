import bb.cascades 1.0

Container {
    layout: DockLayout {}
    ImageView {
        image: "assets:///images/background.png"
        preferredWidth: 768
        preferredHeight: 1280
    }
    Container {
        layout: StackLayout {}
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Center;
            verticalAlignment: VerticalAlignment.Center
        }
        preferredWidth: 768
        preferredHeight: 1280
	    Button {
	        id: loginButton
	        objectName: "login"
	        text: loginLayout.getLoginButtonText()
	        layoutProperties: StackLayoutProperties {
	            verticalAlignment: VerticalAlignment.Center
	            horizontalAlignment: HorizontalAlignment.Center;
	        }
	        onClicked: {
                 loginLayout.onButtonClicked();
             }
	    }
    }
}