import Cascades 4.0

Container {
    layout: DockLayout {
            }
    ImageView {
        image: "assets://images/background"
        preferredWidth: 1024
        preferredHeight: 600
    }
    
    Container {
        layout: StackLayout {
                layoutDirection: StackLayout.LeftToRight;
                }
        preferredWidth: 1024;
        preferredHeight: 500;
        topMargin: 10;
        
	    Container {
	        layout: StackLayout {}
	        layoutProperties: StackLayoutProperties {
                verticalAlignment: VerticalAlignment.Top
            }
	        topMargin: 10
	        bottomMargin: 10
	        leftMargin: 10
	        preferredWidth: 500
	        preferredHeight: 500
	        Label {
	            objectName: "userName"
	            topMargin: 10; bottomMargin: 10;
	            font: SystemFont.H2
	            textColor: Color.create("#ffffffff")
	            layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	        Button {
			    objectName: "logoutButton"
			    text: "Logout"
			    layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	    }
	    
	    Container {
	        layout: StackLayout {}
	        layoutProperties: StackLayoutProperties {
                verticalAlignment: VerticalAlignment.Top
            }
	        topMargin: 10
	        bottomMargin: 10
	        leftMargin: 10
	        preferredWidth: 500
	        preferredHeight: 500
	        TextArea {
	            objectName: "tweetText"
	            topMargin: 10; bottomMargin: 10;
	            preferredWidth: 300;
	            preferredHeight: 150;
	            font: SystemFont.H2
	            layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	        Button {
			    objectName: "postTweetButton"
			    text: "Tweet!"
			    layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	    }
    }
}