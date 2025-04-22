const fs = require("fs");

let [, , command, ...args] = process.argv;

if (command === "add") {
  let title = args.join(" ");

  fs.readFile("data.json", "utf-8", (err, data) => {
    let todos = data ? JSON.parse(data) : [];

    todos.push({
      title,
      id: todos.length === 0 ? 1 : todos[todos.length - 1].id + 1,
    });

    fs.writeFile("data.json", JSON.stringify(todos), () => {
      console.log("Added successfully");
    });
  });

} else if (command === "list") {
  fs.readFile("data.json", "utf-8", (err, data) => {
    let todos = data ? JSON.parse(data) : [];
    if (todos.length === 0) {
      console.log("No todos found");
      return;
    }

    todos.forEach((todo) => {
      console.log(`${todo.id}: ${todo.title}`);
    });
  });

} else if (command === "delete") {
  let id = args[0];

  fs.readFile("data.json", "utf-8", (err, data) => {
    let todos = JSON.parse(data);
    let index = todos.findIndex((todo) => todo.id == id);

    if (index !== -1) {
      todos.splice(index, 1);

      fs.writeFile("data.json", JSON.stringify(todos), () => {
        console.log("Deleted successfully");
      });
    } else {
      console.log("Todo doesn't exist");
    }
  });

} else if (command === "edit") {
  let id = args[0];
  let newTitle = args.slice(1).join(" ");

  fs.readFile("data.json", "utf-8", (err, data) => {
    let todos = JSON.parse(data);
    let index = todos.findIndex((todo) => todo.id == id);

    if (index !== -1) {
      todos[index].title = newTitle;

      fs.writeFile("data.json", JSON.stringify(todos), () => {
        console.log("Edited successfully");
      });
    } else {
      console.log("Todo doesn't exist");
    }
  });

} else {
  console.log("Invalid command. Use add, list, edit, or delete.");
}
