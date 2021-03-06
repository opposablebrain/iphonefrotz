/*

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; version 2
 of the License.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
#import <UIKit/UIKit.h>
#import "FrotzInfo.h"
#import "URLPromptController.h"
#import "BookmarkListController.h"

@class StoryBrowser;

typedef enum { kSWBIdle, kSWBFetchingImage, kSWBFetchingStory } SWBDownloadState;

@interface StoryWebBrowserController : UIViewController <UIWebViewDelegate, KeyboardOwner, URLPromptDelegate, BookmarkDelegate, UIScrollViewDelegate> {
    UIView *m_background; // UIView
    UIWebView *m_webView;
    UIScrollView *m_scrollView;
    StoryBrowser *m_storyBrowser;
    UIToolbar *m_toolBar;
    UIActivityIndicatorView *m_activityView;
    UIBarButtonItem *m_backButtonItem, *m_forwardButtonItem, *m_cancelButtonItem, *m_reloadButtonItem, *m_URLButtonItem, *m_activButtonItem;
    URLPromptController *m_urlBarController;
    BookmarkListController *m_bookmarkListController;

    FrotzInfo *m_frotzInfoController;
    NSURLRequest *m_currentRequest, *m_delayedRequest;
    NSMutableData *m_receivedData;
    SWBDownloadState m_state;
    BOOL m_backToStoryList;
    BOOL m_storyAlreadyInstalled;
    NSMutableArray *m_expectedArchiveFiles;
}
-(StoryWebBrowserController*)initWithBrowser:(StoryBrowser*)sb;
-(void)loadView;
-(void)goBack;
-(void)goForward;
-(void)cancel;
-(void)refresh;
-(void)promptURL;
-(void)enterURL:(NSString*)url;
-(void)dismissURLPrompt;
-(void)showBookmarks;
-(void)hideBookmarks;
-(UIWebView*)webView;
-(void)setupFade;
-(UIActivityIndicatorView*)activityIndicator;
-(UIBarButtonItem*)backButton;
-(BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
-(StoryBrowser*)storyBrowser;
-(FrotzInfo*)frotzInfoController;
-(void)browserDidPressBackButton;
-(BOOL)snarfMetaData: (NSURLRequest*)request loadRequest: (NSURLRequest*)delayedRequest forStory:(NSString*)story;
-(BOOL)savePicData:(NSData*)picData forStory:(NSString*)story;
-(void)loadZFile:(NSURLRequest*)request;
-(NSString*)currentURL;
-(NSString*)currentURLTitle;
-(void)loadBookmarksWithURLs:(NSArray**)urls andTitles:(NSArray**)titles;
-(void)saveBookmarksWithURLs:(NSArray*)urls andTitles:(NSArray*)titles;
-(NSString*)bookmarkPath;

@end


