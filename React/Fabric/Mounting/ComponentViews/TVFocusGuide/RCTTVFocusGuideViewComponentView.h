#import <UIKit/UIKit.h>

#import <React/RCTViewComponentView.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * UIView class for root <TVFocusGuideView> component.
 */
@interface RCTTVFocusGuideViewComponentView : RCTViewComponentView

@property(nonatomic, nullable, strong) UIFocusGuide *focusGuide;

@end

NS_ASSUME_NONNULL_END
