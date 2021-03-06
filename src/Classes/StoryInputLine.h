//
//  StoryInputLine.h
//  Frotz
//
//  Created by Craig Smith on 2/9/10.
//  Copyright 2010 Craig Smith. All rights reserved.
//

#import "StoryMainViewController.h"
#import "CompletionLabel.h"

@interface StoryInputLine: UITextField <FrotzInputDelegate> {
    StoryView *m_storyView;
    StatusLine *m_statusLine;
    UIView *m_enterAndClearView;
    FrotzInputHelper *m_inputHelper;
    UITouchPhase m_lastTouchPhaseSeen;
    NSTimeInterval m_lastTouchTimestamp;
    CGPoint m_touchBeganPosition;
    CompletionLabel *m_completionLabel;
    BOOL m_firstKeyPressed, m_lastCharDeleted;
    BOOL m_justHidHelper;
    BOOL m_completionAmbiguous;
}
-(StoryInputLine*)initWithFrame:(CGRect)frame;
-(StoryView*) storyView;
-(void)setStoryView:(StoryView*)sv;
-(StatusLine*) statusLine;
-(void)setStatusLine:(StatusLine*)sl;
-(void)resetState;
-(BOOL)updatePosition;
-(BOOL)handleTouch: (UITouch*)touch withEvent: (UIEvent*)event;
-(int)addHistoryItem:(NSString*)historyItem;
-(void)inputHelperString:(NSString*)string;
-(void)hideInputHelper;
-(UIView*) inputHelperView;
-(void)setClearButtonMode;
-(void)maybeShowEnterKey;
-(void)hideEnterKey;
-(void)setTextKeepCompletion:(NSString*)text;
@end

