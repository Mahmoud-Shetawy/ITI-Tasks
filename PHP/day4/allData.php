<?php
session_start();

if (!isset($_SESSION["user"])) {
    header("Location: login.php");
    exit;
}

$file = "database.json";
$users = file_exists($file) ? json_decode(file_get_contents($file), true) : [];

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>All Users</title>
</head>
<body>
    <h2>Registered Users</h2>
    <table border="1">
        <tr>
            <th>Name</th>
            <th>Email</th>
            <th>Image</th>
        </tr>
        <?php foreach ($users as $user): ?>
        <tr>
            <td><?= htmlspecialchars($user["name"]) ?></td>
            <td><?= htmlspecialchars($user["email"]) ?></td>
            <td><img src="images/<?= htmlspecialchars($user["image"]) ?>" width="50"></td>
        </tr>
        <?php endforeach; ?>
    </table>

    <p><a href="login.php">Logout</a></p>
</body>
</html>
