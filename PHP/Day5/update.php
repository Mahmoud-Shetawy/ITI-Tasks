<?php
include("index.php");

if (isset($_GET['id'])) {
    $id = $_GET['id'];

    $sql = "SELECT * FROM users WHERE id = :id";
    $query = $dataBase->connection()->prepare($sql);
    $query->bindParam(':id', $id);
    $query->execute();
    $user = $query->fetch(PDO::FETCH_ASSOC);

    if (!$user) {
        echo "User not found!";
        exit;
    }
} else {
    echo "Invalid request!";
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Update Page</title>
</head>
<body>
<div class="register-container d-block">
    <h2>Update User</h2>

    <div>
        <?php
            session_start();
            if (isset($_SESSION['message'])) {
                echo "<p class='alert alert-success d-block m-auto text-center'>".$_SESSION['message']."</p>";
                unset($_SESSION['message']);  
            }            
        ?>
    </div>

    <form action="updateUser.php" method="post">
        <input type="hidden" name="id" value="<?php echo $user['id']; ?>">

        <div class="input-group">
            <label for="name">Name</label>
            <input type="text" id="name" name="name" value="<?php echo $user['name']; ?>" required>
        </div>
        
        <div class="input-group">
            <label for="email">Email</label>
            <input type="email" id="email" name="email" value="<?php echo $user['email']; ?>" required>
        </div>

        <div class="input-group">
            <label for="password">New Password </label>
            <input type="password" id="password" name="password" placeholder="Enter a new password">
        </div>

        <button type="submit" class="register-btn" name="btn-update">Update Now</button>
    </form>
</div>
</body>
</html>
