/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "RCTTVFocusGuideViewComponentView.h"

#import <React/RCTConversions.h>

#import <react/renderer/components/rncore/ComponentDescriptors.h>
#import <react/renderer/components/tvfocusguide/TVFocusGuideViewComponentDescriptor.h>
#import <react/renderer/components/rncore/EventEmitters.h>
#import <react/renderer/components/rncore/Props.h>

#import "RCTFabricComponentsPlugins.h"

using namespace facebook::react;

@implementation RCTTVFocusGuideViewComponentView {
}

#pragma mark - RCTComponentViewProtocol

 + (ComponentDescriptorProvider)componentDescriptorProvider
{
  return concreteComponentDescriptorProvider<TVFocusGuideViewComponentDescriptor>();
}

- (instancetype)initWithFrame:(CGRect)frame
{
  if (self = [super initWithFrame:frame]) {
    static const auto defaultProps = std::make_shared<const TVFocusGuideViewProps>();
    _props = defaultProps;

    self.focusGuide = nil;
  }

  return self;
}

- (void)updateProps:(Props::Shared const &)props oldProps:(Props::Shared const &)oldProps
{
  const auto &oldViewProps = *std::static_pointer_cast<const TVFocusGuideViewProps>(_props);
  const auto &newViewProps = *std::static_pointer_cast<const TVFocusGuideViewProps>(props);
  
  if (oldViewProps.destinationTags != newViewProps.destinationTags) {
    auto const &destinationTags = _props->destinationTags;
    [self setDestinationTags:destinationTags];
  }

  [super updateProps:props oldProps:oldProps];
}

- (void)addFocusGuide:(NSArray*)destinations {
  
  UIView *origin = [self superview];
  if (self.focusGuide == nil && origin != nil) {
    self.focusGuide = [UIFocusGuide new];
    [self addLayoutGuide:self.focusGuide];
    
    [self.focusGuide.widthAnchor constraintEqualToAnchor:origin.widthAnchor].active = YES;
    [self.focusGuide.heightAnchor constraintEqualToAnchor:origin.heightAnchor].active = YES;
    [self.focusGuide.topAnchor constraintEqualToAnchor:origin.topAnchor].active = YES;
    [self.focusGuide.leftAnchor constraintEqualToAnchor:origin.leftAnchor].active = YES;
  }
  
  self.focusGuide.preferredFocusEnvironments = destinations;
}

- (void)setDestinationTags:(std::vector<int> const &)destinationTags
{
  NSMutableArray* destinations = [NSMutableArray array];
  if (!destinationTags.empty()) {
    for (auto const &tag : destinationTags) {
      /*
      UIView *destination = [_mountingManager.componentViewRegistry findComponentViewWithTag:tag];
      if (destination != nil) {
        [destinations addObject:destination];
      }
       */
    }
    [self addFocusGuide:destinations];
  } else {
    self.focusGuide = nil;
  }
}




@end

Class<RCTComponentViewProtocol> RCTTVFocusGuideViewCls(void)
{
  return RCTTVFocusGuideViewComponentView.class;
}
