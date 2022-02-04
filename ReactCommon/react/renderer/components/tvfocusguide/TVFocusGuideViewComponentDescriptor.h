/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <react/debug/react_native_assert.h>
#include <react/renderer/components/tvfocusguide/TVFocusGuideViewShadowNode.h>
#include <react/renderer/core/ConcreteComponentDescriptor.h>

namespace facebook {
namespace react {

/*
 * Descriptor for <TVFocusGuideView> component.
 */
class TVFocusGuideViewComponentDescriptor final
    : public ConcreteComponentDescriptor<TVFocusGuideViewShadowNode> {
 public:
  using ConcreteComponentDescriptor::ConcreteComponentDescriptor;

  void adopt(ShadowNode::Unshared const &shadowNode) const override {
    react_native_assert(
        std::dynamic_pointer_cast<TVFocusGuideViewShadowNode>(shadowNode));
    auto concreteShadowNode =
        std::static_pointer_cast<TVFocusGuideViewShadowNode>(shadowNode);

    react_native_assert(std::dynamic_pointer_cast<YogaLayoutableShadowNode>(
        concreteShadowNode));
    auto layoutableShadowNode =
        std::static_pointer_cast<YogaLayoutableShadowNode>(concreteShadowNode);

    ConcreteComponentDescriptor::adopt(shadowNode);
  }
};

} // namespace react
} // namespace facebook
