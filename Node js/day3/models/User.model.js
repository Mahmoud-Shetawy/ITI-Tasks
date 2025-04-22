import mongoose from "mongoose";

const userSchema = new mongoose.Schema({
  userName: {
    type: String,
    required: true,
    minlength: 3,
    unique: true, // Optional: make usernames unique
    trim: true
  },
  password: {
    type: String,
    required: true
  },
  firstName: {
    type: String,
    required: true,
    minlength: 3,
    maxlength: 15
  },
  lastName: {
    type: String,
    required: true,
    minlength: 3,
    maxlength: 15
  },
  image: {
    type: String, // e.g. "profile.jpg" or image URL
    default: ""
  },
  dob: {
    type: Date
  }
}, { timestamps: true });

const UserModel = mongoose.model("User", userSchema);

export default UserModel;
