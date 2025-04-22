const express = require('express');
const fs = require('fs');
const app = express();
const PORT = 3000;
app.use(express.json());

// ==================function handle read file and write file ===========
const DATA_FILE = 'data.json';

function loadTodos() {
  if (!fs.existsSync(DATA_FILE)) return [];
  const data = fs.readFileSync(DATA_FILE, 'utf-8');
  try {
    return JSON.parse(data) || [];
  } catch {
    return [];
  }
}

function saveTodos(todos) {
  fs.writeFileSync(DATA_FILE, JSON.stringify(todos, null, 2));
}
// =============================add data in the data.json ========
app.post('/todos', (req, res, next) => {
    const { title } = req.body;
  
    if (!title) {
      return res.status(400).json({ error: "Title is required" });
    }
  
    let todos = loadTodos();
    let newtodo = {
      id: todos.length > 0 ? todos[todos.length - 1].id + 1 : 1,
      title: title,
      status: 'new',
    };
  
    todos.push(newtodo);
    saveTodos(todos);
  
    res.status(201).json(newtodo);
  });
  
// get all todos =============

app.get('/todos', (req, res) => {
    let todos = loadTodos();
    console.log(todos);
    res.json({ message: "todosis", todos });
  });
//get one todo 

app.get('/todos/:id', (req, res) => {
    const { id } = req.params;
    const todos = loadTodos();
  
    for (let i = 0; i < todos.length; i++) {
      if (todos[i].id == id) {
        return res.json({ message: "Todo found", todo: todos[i] });
      }
    }
  
    res.status(404).json({ error: "Todo not found" });
  });

////==========delete======
app.delete('/todos/:id', (req, res) => {
    const { id } = req.params;
    const todos = loadTodos();
  
    for (let i = 0; i < todos.length; i++) {
      if (todos[i].id == id) {
        todos.splice(i, 1);  
        saveTodos(todos);    
        return res.json({ message: "Todo deleted successfully" });
      }
    }
  
    res.status(404).json({ error: "Todo not found" });
  });

// =====================updated==============
app.patch('/todos/:id', (req, res) => {
    const { id } = req.params;
    const { title} = req.body;
    const todos = loadTodos();
  
    for (let i = 0; i < todos.length; i++) {
      if (todos[i].id == id) {
              todos[i].title = title  ;
              todos[i].status = "updated";
  
        saveTodos(todos);
  
        return res.json({ message: "Todo updated successfully", todo: todos[i] });
      }
    }
  
    res.status(404).json({ error: "Todo not found" });
  });


// =======================
  
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
  });