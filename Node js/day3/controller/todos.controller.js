import TodoModel from './../models/Todo.model.js'


export const createTodo = async (req, res) => {
  const { title, status, userId } = req.body;

  if (!title || !userId) {
    return res.status(400).json({ message: "Title and userId are required" });
  }

  try {
    const newTodo = await TodoModel.create({ title, status, userId });
    res.status(201).json({ message: "Todo created", data: newTodo });
  } catch (err) {
    res.status(500).json({ message: "Error creating todo", error: err.message });
  }
};


// update Todos 
export const updateTodo = async (req, res) => {
    const { id } = req.params;
  
    try {
      const updated = await TodoModel.findByIdAndUpdate(id, req.body, {
        new: true,
        runValidators: true,
      });
  
      if (!updated) {
        return res.status(404).json({ message: "Todo not found" });
      }
  
      res.status(200).json({ message: "Todo updated", data: updated });
    } catch (err) {
      res.status(500).json({ message: "Error updating todo", error: err.message });
    }
  };

  
//   delete Todo

export const deleteTodo = async (req, res) => {
    const { id } = req.params;
  
    try {
      const deleted = await TodoModel.findByIdAndDelete(id);
      if (!deleted) {
        return res.status(404).json({ message: "Todo not found" });
      }
  
      res.status(200).json({ message: "Todo deleted", data: deleted });
    } catch (err) {
      res.status(500).json({ message: "Error deleting todo", error: err.message });
    }
  };

  

export const getTodosWithUser = async (req, res) => {
  try {
    const todos = await TodoModel.find().populate('userId', 'userName firstName lastName');
    res.status(200).json({ message: 'Todos with user data', data: todos });
  } catch (err) {
    res.status(500).json({ message: 'Error fetching todos', error: err.message });
  }
};


export const getTodosByUser = async (req,res , next ) => {
    const {userId} = req.params
    try {
        const todo = await TodoModel.find({userId})
        if(!todo) {
            res.status(404).json({message : "user to have todo"})
        }
        res.status(200).json({message:"user todo is " , todo})
    }
    catch (err) {
        res.status(500).json({ message: 'Error fetching todos', error: err.message });
      }
}



export const getAllTodos = async (req, res) => {
    const limit = parseInt(req.query.limit) || 10;
    const skip = parseInt(req.query.skip) || 0;
  
    try {
      const todos = await TodoModel.find().limit(limit).skip(skip);
      res.status(200).json({ message: "Todos fetched", data: todos });
    } catch (err) {
      res.status(500).json({ message: "Error fetching todos", error: err.message });
    }
  };
  