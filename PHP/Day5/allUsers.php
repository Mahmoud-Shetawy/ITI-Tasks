<?php 
include("index.php");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>All Users</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
</head>
<body class="container" style="margin-top:7rem;">
<table class="table table-hover">
  <thead>
    <tr>
      <th scope="col">UserName</th>
      <th scope="col">Email</th>
      <th scope="col">Password</th>
      <th scope="col">Action</th>
    </tr>
  </thead>
  <tbody>
    <a href="addUser.php" class="btn btn-success mb-3">Add User</a>

    <?php
    $sql = "SELECT * FROM users";
    $query = $dataBase->connection()->prepare($sql);
    $query->execute();
    $result = $query->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $row) {
        echo "<tr>";
        echo "<td>".$row['name']."</td>";
        echo "<td>".$row['email']."</td>";
        echo "<td>".$row['password']."</td>"; 
        echo "<td>
                <a class='btn btn-warning btn-sm' href='./UserInformation.php?id=".$row['id']."'>Show</a>
                <form method='post' action='./deleteUser.php' style='display:inline;'>
                    <input type='hidden' name='id' value='".$row['id']."'>
                    <button type='submit' class='btn btn-danger btn-sm' name='btn-delete' onclick='return confirm(\"Are you sure you want to delete this user?\")'>Delete</button>
                </form>

                <a class='btn btn-primary btn-sm' href='update.php?id=".$row['id']."'>Update</a>
              </td>";
        echo "</tr>";
    }
    ?>
  </tbody>
</table>
</body>
</html>
