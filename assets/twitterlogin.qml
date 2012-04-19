import Cascades 4.0

Container {
    layout: DockLayout {}
    ImageView {
        image: "assets://images/background"
        preferredWidth: 1024
        preferredHeight: 600
    }
    Container {
        layout: StackLayout {}
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Center;
            verticalAlignment: VerticalAlignment.Center
        }
        preferredWidth: 500
        preferredHeight: 200
	    Button {
	        id: loginButton
	        objectName: "login"
	        text: "Login"
	        layoutProperties: StackLayoutProperties {
	            verticalAlignment: VerticalAlignment.Center
	            horizontalAlignment: HorizontalAlignment.Center;
	        }
	    }
    }
}