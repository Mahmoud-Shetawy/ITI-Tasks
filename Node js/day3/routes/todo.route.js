import { Router } from 'express'
import {createTodo, updateTodo , deleteTodo , getTodosWithUser , getTodosByUser , getAllTodos} from './../controller/todos.controller.js'
const router = Router()

router.post("/todos", createTodo);
router.get("/todos", getTodosWithUser);
router.patch("/todos/:id", updateTodo);
router.delete("/todos/:id", deleteTodo);
router.get("/users/:userId/todos", getTodosByUser);
router.get("/alltodos", getAllTodos);


export default router 