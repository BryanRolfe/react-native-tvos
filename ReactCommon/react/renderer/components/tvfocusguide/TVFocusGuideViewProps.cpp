/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "TVFocusGuideViewProps.h"

#include <react/renderer/attributedstring/conversions.h>
#include <react/renderer/core/propsConversions.h>
#include <react/renderer/graphics/conversions.h>
#include <react/renderer/components/view/conversions.h>
#include <react/renderer/components/view/propsConversions.h>

namespace facebook {
namespace react {

TVFocusGuideViewProps::TVFocusGuideViewProps(
    const PropsParserContext &context,
    ViewProps const &sourceProps,
    RawProps const &rawProps)
    : ViewProps(context, sourceProps, rawProps),
    destinationTags(convertRawProp(context, rawProps, "destinationTags", sourceProps.destinationTags, {})){};


} // namespace react
} // namespace facebook
