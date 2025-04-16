<?php
    include("index.php");
    
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Add User Page</title>
</head>
<body>
<div class="register-container d-block ">
    <h2>Add USer</h2>
    <!-- <form action="../Server/server.php" method="post"> -->
    <div>
        <?php
            if(isset($_GET['message'])){
                echo "<p class='alert alert-success  d-block m-auto text-center'>".$_GET["message"] ."</p";
            }
        ?>
    </div>
    <form action="server.php" method="post" >
        <div class="input-group">
            <label for="name">Name</label>
            <input type="text" id="name" name="name" placeholder="Your Name" required>
        </div>
        
        <div class="input-group">
            <label for="email">Email</label>
            <input type="email" id="email" name="email" placeholder="Enter your email" required>
        </div>
        <div class="input-group">
            <label for="password">Password</label>
            <input type="password" id="password" name="password"placeholder="Enter your password" required>
        </div>
        <!-- <div class="input-group">
            <label for="img">Upload Image</label>
            <input type="file" id="img" name="img"placeholder="Upload Your Image" accept="../images/*" required>
        </div> -->
        <button type="submit" class="register-btn" name="btn-add" value="register">Add Now</button>
        
    </form>
</div>

</body>
</html>