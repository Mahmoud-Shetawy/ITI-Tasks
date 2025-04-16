<?php
include("index.php");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Login Page</title>
</head>
<body>
<div class="login-container">
    <h2>Login</h2>
    <div>
        <?php
            if(isset($_GET['message'])){
                echo "<p class='alert alert-success  d-block m-auto text-center'>".$_GET["message"] ."</p";
            }
        ?>
    </div>
    <form action="server.php" method="post">
        <div class="input-group">
            <label for="email">Email</label>
            <input type="email" id="email" name="email"placeholder="Enter your email" required>
        </div>
        <div class="input-group">
            <label for="password">Password</label>
            <input type="password" id="password" name="password" placeholder="Enter your password" required>
        </div>
        <button type="submit" class="login-btn" name="btn-login" value="login">Login</button>
    </form>
</div>

</body>
</html>