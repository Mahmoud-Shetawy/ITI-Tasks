<?php
require('Connection.php');

if(isset($_POST['btn-register'])){
    $username = $_POST['name'];
    $email = $_POST['email'];
    $password = md5($_POST['password']);

    /**===== Name,Email and Password Pattern ======= */
    $namePattern = "/^[a-zA-Z ]{3,}$/";
    $emailPattern = "/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/";
    $passwordPattern = "/^[a-zA-Z0-9._-]{8,}$/";

    if (!preg_match($namePattern, $username)) {
        header('location:register.php?message= "Invalid Name! Must be greater than 3 letters."');
        exit;
    }
    if (!preg_match($emailPattern, $email)) {
        header('location:register.php?message="Invalid Email! Must be in the format aya12@gmail.com."');
        exit;
    }
    if (!preg_match($passwordPattern, $password)) {
        header('location:register.php?message="Invalid Password! Must be at least 8 characters."');
        exit;
    }

    /**======= Check Authentication Email with Sql Injection ============ */


    $checkEmailExist = "select * from `users` where email = :email";
    $sqlQuery = $dataBase->connection()->prepare($checkEmailExist);
    $sqlQuery->bindParam(':email', $email);
    $sqlQuery->execute();
    // $sqlQuery= $dataBase->query($checkEmailExist);
    $result = $sqlQuery->fetch(PDO::FETCH_ASSOC);
    if($result){
        header('location:register.php?message="Email already exist!!"');
        exit;
    };

    /**===== Add User Data to DataBase  ============ */
    $insertQuery = "insert into users (name, email, password) values (:username,:email,:password)";
    $sqlQuery = $dataBase->connection()->prepare($insertQuery);
    $sqlQuery->bindParam(':username',$username);
    $sqlQuery->bindParam(':email',$email);
    $sqlQuery->bindParam(':password',$password);
    $resultInsert=$sqlQuery->execute();
    // $resultInsert = $dataBase->query($insertQuery);
    if($resultInsert){
        header('location:register.php?message=Registration successful!');
        exit;
    }else {
        header('location:register.php?message="Registration failed! Please try again."');
        exit;
    }
}
/**========= Login Form ================= */
if(isset($_POST['btn-login'])){
    $email = $_POST['email'];
    $password = md5($_POST['password']);

    /**===== Name,Email and Password Pattern ======= */
    $emailPattern = "/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/";
    $passwordPattern = "/^[a-zA-Z0-9._-]{8,}$/";

    if (!preg_match($emailPattern, $email)) {
        header('location:register.php?message="Invalid Email! Must be in the format aya12@gmail.com."');
        exit;
    }
    if (!preg_match($passwordPattern, $password)) {
        header('location:register.php?message="Invalid Password! Must be at least 8 characters."');
        exit;
    }

    /**======= Check Authentication Email & Password with Sql Injection ============ */


    $checkEmailExist = "select * from `users` where email = :email";
    $sqlQuery = $dataBase->connection()->prepare($checkEmailExist);
    $sqlQuery->bindParam(':email', $email);
    $sqlQuery->execute();
    // $sqlQuery= $dataBase->query($checkEmailExist);
    $emailResult = $sqlQuery->fetch(PDO::FETCH_ASSOC);
    //Password
    $checkPassword = "select * from `users` where password = :password";
    $sqlQuery = $dataBase->connection()->prepare($checkPassword);
    $sqlQuery->bindParam(':password', $password);
    $sqlQuery->execute();
    // $sqlQuery= $dataBase->query($checkEmailExist);
    $passwordResult = $sqlQuery->fetch(PDO::FETCH_ASSOC);
    if($emailResult['email'] == $email && $passwordResult['password'] == $password){
        
        header('location:allUsers.php?message="Welcome to all data!!"');
        exit;
    }else{
        header('location:login.php?message="Invalid Email or Password!"');
    }

    /**================================================== */
    /**===== Add User Data to DataBase  ============ */
    // $insertQuery = "insert into users (name, email, password) values (:username,:email,:password)";
    // $sqlQuery = $dataBase->connection()->prepare($insertQuery);
    // $sqlQuery->bindParam(':username',$username);
    // $sqlQuery->bindParam(':email',$email);
    // $sqlQuery->bindParam(':password',$password);
    // $resultInsert=$sqlQuery->execute();
    // // $resultInsert = $dataBase->query($insertQuery);
    // if($resultInsert){
    //     header('location:register.php?message=Registration successful!');
    //     exit;
    // }else {
    //     header('location:register.php?message="Registration failed! Please try again."');
    //     exit;
    // }
}


/**============== Add User =============== */
if(isset($_POST['btn-add'])){
    $username = $_POST['name'];
    $email = $_POST['email'];
    $password = md5($_POST['password']);

    /**===== Name,Email and Password Pattern ======= */
    $namePattern = "/^[a-zA-Z ]{3,}$/";
    $emailPattern = "/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/";
    $passwordPattern = "/^[a-zA-Z0-9._-]{8,}$/";

    if (!preg_match($namePattern, $username)) {
        header('location:register.php?message= "Invalid Name! Must be greater than 3 letters."');
        exit;
    }
    if (!preg_match($emailPattern, $email)) {
        header('location:register.php?message="Invalid Email! Must be in the format aya12@gmail.com."');
        exit;
    }
    if (!preg_match($passwordPattern, $password)) {
        header('location:register.php?message="Invalid Password! Must be at least 8 characters."');
        exit;
    }

    /**======= Check Authentication Email with Sql Injection ============ */


    $checkEmailExist = "select * from `users` where email = :email";
    $sqlQuery = $dataBase->connection()->prepare($checkEmailExist);
    $sqlQuery->bindParam(':email', $email);
    $sqlQuery->execute();
    // $sqlQuery= $dataBase->query($checkEmailExist);
    $result = $sqlQuery->fetch(PDO::FETCH_ASSOC);
    if($result){
        header('location:register.php?message="Email already exist!!"');
        exit;
    };

    /**===== Add User Data to DataBase  ============ */
    $insertQuery = "insert into users (name, email, password) values (:username,:email,:password)";
    $sqlQuery = $dataBase->connection()->prepare($insertQuery);
    $sqlQuery->bindParam(':username',$username);
    $sqlQuery->bindParam(':email',$email);
    $sqlQuery->bindParam(':password',$password);
    $resultInsert=$sqlQuery->execute();
    // $resultInsert = $dataBase->query($insertQuery);
    if($resultInsert){
        header('location:register.php?message=Add User successful!');
        exit;
    }else {
        header('location:register.php?message="Add User failed! Please try again."');
        exit;
    }
}


?>