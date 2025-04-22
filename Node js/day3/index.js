import express from 'express'
import mongoose from 'mongoose'
import userRoutes from './routes/user.route.js'
import todoRouter from './routes/todo.route.js'
const app = express()
const port = 3000
app.use(express.json())
 
mongoose.connect("mongodb://localhost:27017/lap3")
  .then(() => {
    console.log("Connected to database");
  })
  .catch((err) => {
    console.error("Connection failed:", err.message);
  });

  app.use('/', userRoutes); 
  app.use('/', todoRouter); 

// port Runing-----------
app.listen(port , () => {
    console.log(`server run ............. ${port}`)
})
