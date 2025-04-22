import UserModel from "../models/User.model.js";

// add user 
export const addUser = async (req, res) => {
    const {userName , password} = req.body
  if (!userName|| !password) {
    return res.status(400).json({ message: "userName or password is missing" });
  }

  try {
    const newUser = await UserModel.create(req.body);
    res.status(201).json({ message: "User added", data: newUser });
  } catch (err) {
    res.status(500).json({ message: "Failed to add user", error: err.message });
  }
};


// get all user
export const allUser = async (req, res) => {
  try {
    const allUsers = await UserModel.find({});
    res.status(200).json({ message: "Success", data: allUsers });
  } catch (err) {
    res.status(500).json({ message: "Error fetching users", error: err.message });
  }
};

// get one user 
export const oneUser = async (req, res) => {
  const { id } = req.params;

  if (!id) {
    return res.status(400).json({ message: "Missing user ID" });
  }

  try {
    const user = await UserModel.findById(id);
    if (!user) {
      return res.status(404).json({ message: "User not found" });
    }
    res.status(200).json({ message: "Success", data: user });
  } catch (err) {
    res.status(500).json({ message: "Error fetching user", error: err.message });
  }
};
// update user 



export const updateUser = async (req, res) => {
  const { id } = req.params;

  if (!id) {
    return res.status(400).json({ message: "User ID is required" });
  }

  try {
    const updatedUser = await UserModel.findByIdAndUpdate(id, req.body, {
      new: true,            // Return the updated document
      runValidators: true,  // Run schema validations
    });

    if (!updatedUser) {
      return res.status(404).json({ message: "User not found" });
    }

    res.status(200).json({ message: "User updated successfully", data: updatedUser });
  } catch (err) {
    res.status(500).json({ message: "Failed to update user", error: err.message });
  }
};


// delete user 


export const deleteUser = async (req, res) => {
    const { id } = req.params;
  
    if (!id) {
      return res.status(400).json({ message: "User ID is required" });
    }
  
    try {
      const deletedUser = await UserModel.findByIdAndDelete(id);
  
      if (!deletedUser) {
        return res.status(404).json({ message: "User not found" });
      }
  
      res.status(200).json({ message: "User deleted successfully", data: deletedUser });
    } catch (err) {
      res.status(500).json({ message: "Failed to delete user", error: err.message });
    }
}  




