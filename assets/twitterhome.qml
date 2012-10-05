import bb.cascades 1.0

Container {
    layout: DockLayout {
            }
    ImageView {
        imageSource: "asset:///images/background.png"
        preferredWidth: 768
        preferredHeight: 1280
    }
    
    Container {
        layout: StackLayout {}
        preferredWidth: 768;
        preferredHeight: 1280;
        topMargin: 10;
        
	    Container {
	        layout: StackLayout {}
            verticalAlignment: VerticalAlignment.Top
	        topMargin: 10
	        bottomMargin: 10
	        leftMargin: 10
	        preferredWidth: 768
	        preferredHeight: 768
	        Label {
	            topMargin: 10; bottomMargin: 10;
	            textStyle {       
		            base: SystemDefaults.TextStyles.TitleText             
		            color: Color.Black      
	                fontWeight: FontWeight.Bold     
                 }
	            text: twitterUser.name
	            horizontalAlignment: HorizontalAlignment.Left;
	        }
	        Label {
	            topMargin: 10; bottomMargin: 10;
	            textStyle {       
		            base: SystemDefaults.TextStyles.TitleText             
		            color: Color.Black      
	                fontWeight: FontWeight.Bold     
                 }
	            text: twitterUser.screenName
	            horizontalAlignment: HorizontalAlignment.Left;
	        }
	        Label {
	            topMargin: 10; bottomMargin: 10;
	            textStyle {       
	            		            base: SystemDefaults.TextStyles.TitleText             
	            		            color: Color.Black      
	            	                fontWeight: FontWeight.Bold     
	                             }
	            text: twitterUser.url
	            horizontalAlignment: HorizontalAlignment.Left;
	        }
	        Label {
	            topMargin: 10; bottomMargin: 10;
	            text: twitterUser.location
	            horizontalAlignment: HorizontalAlignment.Left;
	        }
	        Button {
			    objectName: "logoutButton"
			    text: "Logout"
			    horizontalAlignment: HorizontalAlignment.Left;
			    onClicked: {
			        homeView.onLogoutClicked()
			    }
	        }
	    }
	    
	    Container {
	        layout: StackLayout {}
            verticalAlignment: VerticalAlignment.Top
	        topMargin: 10
	        bottomMargin: 10
	        leftMargin: 10
	        preferredWidth: 768
	        preferredHeight: 768
	        TextArea {
	            id: tweetText
	            objectName: "tweetText"
	            topMargin: 10; bottomMargin: 10;
	            preferredWidth: 768;
	            preferredHeight: 250;
	            textStyle {       
		            base: SystemDefaults.TextStyles.TitleText             
		            color: Color.Black      
	                fontWeight: FontWeight.Bold     
                 }
                 horizontalAlignment: HorizontalAlignment.Left;
	        }
	        Button {
			    text: "Tweet!"
			    horizontalAlignment: HorizontalAlignment.Left;
			    onClicked: {
			        homeView.onTweetClicked(tweetText.text)
			    }
	        }
	    }
    }
}