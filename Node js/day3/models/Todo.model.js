import mongoose from 'mongoose';

const todoSchema = new mongoose.Schema({

  title: {
    type: String,
    required: true,
    minlength: 5,
    maxlength: 20
  },
  status: {
    type: String,
    enum: ['to-do', 'in progress', 'done'],
    default: 'to-do'
  } ,  userId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'User',
    required : true
  }
   
}, { timestamps: true }); 

const TodoModel = mongoose.model('Todo', todoSchema);
export default TodoModel;
