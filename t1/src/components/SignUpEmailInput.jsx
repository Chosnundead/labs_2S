import React, { useState } from "react";

const SignUpEmailInput = (props) => {
  const [value, setValue] = useState("");
  const [isValid, setIsValid] = useState(false);
  const _checkValid = (event) => {
    setValue(event.target.value);
    if (event.target.value.search("@") != -1) {
      setIsValid(true);
      props.dataFunction(true);
    } else {
      setIsValid(false);
      props.dataFunction(false);
    }
  };
  return (
    <p>
      <text>E-mail</text>
      <input
        {...props}
        value={value}
        onChange={_checkValid}
        data-valid={isValid}
      />
    </p>
  );
};
export default SignUpEmailInput;
