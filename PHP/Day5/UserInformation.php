<?php 
// include("index.php");
require('Connection.php');
$userID=$_GET['id'];
if(!$userID)
{
   include('./pageNotFound.php');
   exit;
}else{
    $userData=$dataBase->getUser("users",$userID);
    if(!$userData)
    {
        include('./pageNotFound.php');
       exit;

}}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Information</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
</head>
<body class="container" style="margin-top:10rem;">

<table class="table table-hover">
<h1 class="text-primary text-center text-capitalize">User Information </h1>
  <thead>
    <tr>
      <th scope="col">UserName</th>
      <th scope="col">Email</th>
      <th scope="col">Password</th>
      <th scope="col">Action</th>
    </tr>
  </thead>
  <tbody>
    <?php
        echo "<tr>";
        echo "<td>".$userData['name']."</td>";
        echo "<td>".$userData['email']."</td>";
        echo "<td>".$userData['password']."</td>"; 
        echo "<td>
                <form method='post' action='./deleteUser.php' style='display:inline;'>
                    <input type='hidden' name='id' value='".$userData['id']."'>
                    <button type='submit' class='btn btn-danger btn-sm' name='btn-delete' onclick='return confirm(\"Are you sure you want to delete this user?\")'>Delete</button>
                </form>

                <a class='btn btn-primary btn-sm' href='update.php?id=".$userData['id']."'>Update</a>
              </td>";
        echo "</tr>";
    ?>
  </tbody>
</table>
</body>
</html>
