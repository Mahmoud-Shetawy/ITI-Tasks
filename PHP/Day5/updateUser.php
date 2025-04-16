<?php 
require ('Connection.php');
if(isset($_POST['btn-update'])){
    $id = $_POST['id']; 
    $newUserName = $_POST['name'];
    $newEmail = $_POST['email'];
    $newPassword = md5($_POST['password']);

    $namePattern = "/^[a-zA-Z ]{3,}$/";
    $emailPattern = "/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/";
    $passwordPattern = "/^[a-zA-Z0-9._-]{8,}$/";

    if (!preg_match($namePattern, $newUserName)) {
        header('location:update.php?message= "Invalid Name! Must be greater than 3 letters."');
        exit;
    }
    if (!preg_match($emailPattern, $newEmail)) {
        header('location:update.php?message="Invalid Email! Must be in the format aya12@gmail.com."');
        exit;
    }
    if (!preg_match($passwordPattern, $newPassword)) {
        header('location:update.php?message="Invalid Password! Must be at least 8 characters."');
        exit;
    }

    /** Check if Email Exists **/
    $checkEmailExist = "SELECT * FROM `users` WHERE email = :email AND id != :id";
    $sqlQuery = $dataBase->connection()->prepare($checkEmailExist);
    $sqlQuery->bindParam(':email', $newEmail);
    $sqlQuery->bindParam(':id', $id);
    $sqlQuery->execute();
    $result = $sqlQuery->fetch(PDO::FETCH_ASSOC);
    
    if($result){
        header('location:update.php?message="Email already exists!!"');
        exit;
    }

    try {
        
        $sqlQuery = "UPDATE users SET name = :newUserName, email = :newEmail, password = :newPassword WHERE id = :id";
        $data = $dataBase->connection()->prepare($sqlQuery);
        $data->bindParam(':newUserName', $newUserName);
        $data->bindParam(':newEmail', $newEmail);
        $data->bindParam(':newPassword', $newPassword);
        $data->bindParam(':id', $id);
        $result = $data->execute();

        if ($result) {
            session_start();
            $_SESSION['message'] = "User updated successfully!";
            header('location:update.php?id='.$id);
            exit;
        } else {
            session_start();
            $_SESSION['message'] = "Failed to update user!";
            header('location:update.php?id='.$id);
            exit;
        }
    } catch(PDOException $e) {
        header('location:update.php?message="Error: ' . $e->getMessage() . '"');
        exit;
    }
}
?>