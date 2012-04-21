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
	            topMargin: 10; bottomMargin: 10;
	            font: SystemFont.H2
	            text: twitterUser.name
	            textColor: Color.create("#ffffffff")
	            layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	        Label {
	            topMargin: 10; bottomMargin: 10;
	            font: SystemFont.H2
	            text: twitterUser.screenName
	            textColor: Color.create("#ffffffff")
	            layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	        Label {
	            topMargin: 10; bottomMargin: 10;
	            font: SystemFont.H2
	            text: twitterUser.url
	            textColor: Color.create("#ffffffff")
	            layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	        Label {
	            topMargin: 10; bottomMargin: 10;
	            font: SystemFont.H2
	            text: twitterUser.location
	            textColor: Color.create("#ffffffff")
	            layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	        Button {
			    objectName: "logoutButton"
			    text: "Logout"
			    layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
			    onClicked: {
			        homeView.onLogoutClicked()
			    }
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
	            id: tweetText
	            objectName: "tweetText"
	            topMargin: 10; bottomMargin: 10;
	            preferredWidth: 300;
	            preferredHeight: 150;
	            font: SystemFont.H2
	            layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
	        }
	        Button {
			    text: "Tweet!"
			    layoutProperties: StackLayoutProperties {horizontalAlignment: HorizontalAlignment.Left;}
			    onClicked: {
			        homeView.onTweetClicked(tweetText.text)
			    }
	        }
	    }
    }
}