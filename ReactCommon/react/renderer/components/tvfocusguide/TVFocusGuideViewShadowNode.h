/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <react/renderer/components/tvfocusguide/TVFocusGuideViewProps.h>
#include <react/renderer/components/rncore/EventEmitters.h>
#include <react/renderer/components/rncore/Props.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>

namespace facebook {
namespace react {

extern const char TVFocusGuideViewComponentName[];

/*
 * `ShadowNode` for <TVFocusGuideView> component.
 */
class TVFocusGuideViewShadowNode final : public ConcreteViewShadowNode<
                                           TVFocusGuideViewComponentName,
                                           TVFocusGuideViewProps> {
 public:
  using ConcreteViewShadowNode::ConcreteViewShadowNode;

};

} // namespace react
} // namespace facebook
