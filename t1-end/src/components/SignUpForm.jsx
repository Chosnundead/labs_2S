import React, { useState } from "react";
import SignUpEmailInput from "./SignUpEmailInput";
import SignUpPasswordInput from "./SignUpPasswordInput";

import PhoneInput from "./PhoneInput";

const SignUpForm = () => {
  const [isValid, setIsValid] = useState([false, false]);
  const _updateEmail = (props) => {
    setIsValid([props, isValid[1]]);
  };
  const _updatePassword = (props) => {
    setIsValid([isValid[0], props]);
  };
  return (
    <form>
      <SignUpEmailInput dataFunction={_updateEmail} />
      <SignUpPasswordInput dataFunction={_updatePassword} />
      <p>
        Фамилия
        <input />
        Имя
        <input />
        Отчество
        <input />
      </p>
      <p>
        <input
          type="radio"
          name="sex"
          style={{ display: "inline", width: "20px" }}
        />
        Мужчина
        <input
          type="radio"
          name="sex"
          style={{ display: "inline", width: "20px" }}
        />
        Женщина
      </p>
      <p>
        <input type="date" />
      </p>
      <p>
        <PhoneInput />
      </p>
      {isValid[0] == true && isValid[1] == true && (
        <button>Отправить форму</button>
      )}
    </form>
  );
};

export default SignUpForm;
