<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
</head>
<body>
    <?php
    if(isset($_GET["message"])) {
        echo "<p style='color:red;'>" . $_GET['message'] . "</p>";
    }
    ?>

    <form action="server.php" method="post" enctype="multipart/form-data">
        <input type="text" name="name" placeholder="Enter Your Name" required><br>
        <input type="email" name="email" placeholder="Enter Your Email" required><br>
        <input type="password" name="password" placeholder="Enter Your Password" required><br>
        <input type="file" name="img" required><br>
        <button type="submit" name="btnRegister">Register</button>
    </form>
</body>
</html>
