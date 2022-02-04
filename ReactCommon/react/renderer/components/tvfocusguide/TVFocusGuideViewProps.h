/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <react/renderer/components/view/ViewProps.h>
#include <react/renderer/core/Props.h>
#include <react/renderer/core/PropsParserContext.h>
#include <react/renderer/core/propsConversions.h>
#include <vector>

namespace facebook {
namespace react {

class TVFocusGuideViewProps final : public ViewProps {
 public:
  TVFocusGuideViewProps() = default;
  TVFocusGuideViewProps(
      const PropsParserContext &context,
      ViewProps const &sourceProps,
      RawProps const &rawProps);

#pragma mark - Props

  std::vector<int> destinationTags;

};

} // namespace react
} // namespace facebook

