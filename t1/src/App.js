import React, { useState } from "react";
import Counter from "./components/Counter";
import Chess from "./components/Chess";
import TableOfStocks from "./components/TableOfStocks";
import TodaysDate from "./components/TodaysDate";
import ProfessionsMenu from "./components/ProfessionsMenu";
import PhoneInput from "./components/PhoneInput";
import SortTable from "./components/SortTable";
import Calendar from "./components/Calendar";
import SignUpForm from "./components/SignUpForm";
import StudentInfo from "./components/StudentInfo";
import Notes from "./components/Notes";

function App(props) {
  // const [value, setValue] = useState("Text");
  switch (props.lab) {
    case "1":
      return (
        <div className="lab1">
          <TodaysDate time={{ timeZone: "+0300", format: 24 }}></TodaysDate>
          <TableOfStocks></TableOfStocks>
          <Chess></Chess>
          {/* <input
            type="text"
            value={value}
            onChange={(event) => setValue(event.target.value)}
          ></input> */}
        </div>
      );
    case "2":
      return (
        <div className="lab2">
          <ProfessionsMenu></ProfessionsMenu>
          <TodaysDate time={{ timeZone: "+0300", format: 12 }}></TodaysDate>
          <TodaysDate time={{ timeZone: "+0000", format: 12 }}></TodaysDate>
        </div>
      );
    case "3":
      return (
        <div className="lab3">
          <PhoneInput></PhoneInput>
          <SortTable></SortTable>
        </div>
      );
    case "4":
      return (
        <div className="lab4">
          <Calendar></Calendar>
        </div>
      );
    case "5":
      return (
        <div className="lab5">
          <SignUpForm />
        </div>
      );
    case "6":
      return (
        <div className="lab6">
          <StudentInfo />
          <hr />
          <Notes />
        </div>
      );
  }
}

export default App;
