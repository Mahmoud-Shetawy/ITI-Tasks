<?php
session_start();

// Create images folder if it doesn't exist
if (!is_dir("images")) {
    mkdir("images");
}

// Registration Logic
if (isset($_POST["btnRegister"])) {
    $name = trim($_POST["name"]);
    $email = trim($_POST["email"]);
    $password = trim($_POST["password"]);
    $image = $_FILES["img"];

    // Validate Image
    $validExtensions = ["jpeg", "jpg", "png"];
    $imgExtension = strtolower(pathinfo($image["name"], PATHINFO_EXTENSION));

    if (!in_array($imgExtension, $validExtensions)) {
        header("Location: register.php?message=Invalid file type. Only JPG, JPEG, PNG allowed.");
        exit;
    }

    if ($image["size"] > 1000000) { // 1MB limit
        header("Location: register.php?message=Image must be less than 1MB.");
        exit;
    }

    // Save Image with Unique Name
    $newImage = time() . '.' . $imgExtension;
    move_uploaded_file($image["tmp_name"], "images/" . $newImage);

    // Store Data in JSON
    $user = [
        "name" => $name,
        "email" => $email,
        "password" => password_hash($password, PASSWORD_DEFAULT), // Encrypt password
        "image" => $newImage
    ];

    $file = "database.json";
    if (!file_exists($file)) {
        file_put_contents($file, json_encode([]));
    }

    $data = json_decode(file_get_contents($file), true);
    $data[] = $user;
    file_put_contents($file, json_encode($data, JSON_PRETTY_PRINT));

    header("Location: login.php");
    exit;
}

// Login Logic
if (isset($_POST["btnLogin"])) {
    $email = trim($_POST["email"]);
    $password = trim($_POST["password"]);

    $file = "database.json";
    if (!file_exists($file)) {
        header("Location: login.php?message=No registered users found.");
        exit;
    }

    $data = json_decode(file_get_contents($file), true);
    foreach ($data as $user) {
        if ($user["email"] === $email && password_verify($password, $user["password"])) {
            $_SESSION["user"] = $user;
            header("Location: allData.php");
            exit;
        }
    }

    header("Location: login.php?message=Invalid email or password.");
    exit;
}
?>