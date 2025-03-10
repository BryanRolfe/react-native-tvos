/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * @flow strict-local
 * @format
 */

import * as React from 'react';
import StyleSheet from '../../StyleSheet/StyleSheet';
import Platform from '../../Utilities/Platform';
import TouchableWithoutFeedback from '../../Components/Touchable/TouchableWithoutFeedback';
import TouchableHighlight from '../../Components/Touchable/TouchableHighlight';
import View from '../../Components/View/View';
import * as LogBoxStyle from './LogBoxStyle';
import type {EdgeInsetsProp} from '../../StyleSheet/EdgeInsetsPropType';
import type {ViewStyleProp} from '../../StyleSheet/StyleSheet';
import type {PressEvent} from '../../Types/CoreEventTypes';

const LogBoxTouchable = Platform.isTVOS ?
                            TouchableHighlight :
                            TouchableWithoutFeedback;

type Props = $ReadOnly<{|
  backgroundColor: $ReadOnly<{|
    default: string,
    pressed: string,
  |}>,
  children?: React.Node,
  hitSlop?: ?EdgeInsetsProp,
  onPress?: ?(event: PressEvent) => void,
  style?: ViewStyleProp,
|}>;

function LogBoxButton(props: Props): React.Node {
  const [pressed, setPressed] = React.useState(false);

  let backgroundColor = props.backgroundColor;
  if (!backgroundColor) {
    backgroundColor = {
      default: LogBoxStyle.getBackgroundColor(0.95),
      pressed: LogBoxStyle.getBackgroundColor(0.6),
    };
  }

  const content = (
    <View
      style={StyleSheet.compose(
        {
          backgroundColor: pressed
            ? backgroundColor.pressed
            : backgroundColor.default,
        },
        props.style,
      )}>
      {props.children}
    </View>
  );

  return props.onPress == null ? (
    content
  ) : (
    <LogBoxTouchable
      hitSlop={props.hitSlop}
      onPress={props.onPress}
      onPressIn={() => setPressed(true)}
      onPressOut={() => setPressed(false)}>
      {content}
    </LogBoxTouchable>
  );
}

export default LogBoxButton;
