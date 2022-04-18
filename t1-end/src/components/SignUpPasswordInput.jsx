import React, { useState } from "react";

const SignUpPasswordInput = (props) => {
  const [value, setValue] = useState(["", ""]);
  const [isValid, setIsValid] = useState(["Пароль не надёжен!", false]);
  const _changeFirst = (event) => {
    setValue([event.target.value, value[1]]);
    props.dataFunction(_checkValid([event.target.value, value[1]]));
  };
  const _changeSecond = (event) => {
    setValue([value[0], event.target.value]);
    props.dataFunction(_checkValid([value[0], event.target.value]));
  };
  const _checkValid = (props) => {
    if (props[0].length <= 8) {
      setIsValid(["Пароль не надёжен!", false]);
    } else if (
      props[0].search(/[A-Z]/g) == -1 ||
      props[0].search(/[1-9]/g) == -1
    ) {
      setIsValid(["Пароль слаб!", false]);
    } else if (
      props[0].search(/[A-Z]/g) != -1 &&
      props[0].search(/[1-9]/g) != -1 &&
      props[0] != props[1]
    ) {
      setIsValid(["Пароли не совпадают!", false]);
    } else {
      setIsValid(["Пароль надежен!", true]);
      return true;
    }
    return false;
  };
  return (
    <p>
      <text>Пароль</text>
      <input
        {...props}
        type="password"
        onChange={_changeFirst}
        value={value[0]}
      />
      <text>Подтверждение пароля</text>
      <input
        {...props}
        type="password"
        onChange={_changeSecond}
        value={value[1]}
      />
      {isValid[1] == true && (
        <text style={{ color: "green" }}>{isValid[0]}</text>
      )}
      {isValid[1] == false && (
        <text style={{ color: "red" }}>{isValid[0]}</text>
      )}
    </p>
  );
};

export default SignUpPasswordInput;
