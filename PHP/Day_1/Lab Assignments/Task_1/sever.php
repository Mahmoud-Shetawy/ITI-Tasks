<?php
    $first_name = $_POST['first_name'] ?? '';
    $last_name = $_POST['last_name'] ?? '';
    $address = $_POST['address'] ?? '';
    $country = $_POST['country'] ?? '';
    $gender = $_POST['gender'] ?? '';
    $username = $_POST['username'] ?? '';
    $password = $_POST['password'] ?? '';



    echo "<h2>Form Data Submitted:</h2>";
    echo "<p>First Name: $first_name</p>";
    echo "<p>Last Name: $last_name</p>";
    echo "<p>Address: $address</p>";
    echo "<p>Country: $country</p>";
    echo "<p>Gender: $gender</p>";
    echo "<p>Username: $username</p>";
    echo "<p>Password: $password</p>";

    exit; 
?>