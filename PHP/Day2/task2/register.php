<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        form {
            background: white;
            padding: 30px;
            border-radius: 10px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2);
            width: 350px;
            display: flex;
            flex-direction: column;
            gap: 15px;
        }

        label {
            font-weight: bold;
            margin-bottom: 5px;
            display: block;
            font-family: 'Courier New', Courier, monospace;
            letter-spacing: 1px;
            color:#e68900
        }
        h2{
            text-align: center;
            color:#e68900;
            font-family: 'Courier New', Courier, monospace;
        }
        input {
            width: 100%;
            padding: 10px;
            border-radius: 5px;
            border: 1px solid #ccc;
            font-size: 14px;
        }

        button {
            width: 100%;
            background-color: #ff9800;
            color: white;
            border: none;
            padding: 10px;
            font-size: 16px;
            border-radius: 5px;
            cursor: pointer;
            transition: 0.3s;
        }

        button:hover {
            background-color: #e68900;
        }

    </style>
</head>
<body>
    <section style="display: flex; justify-content: center; align-items: center; margin-top: 50px;">
    <form action="./server.php" method="post" style="box-sizing: content-box; box-shadow:burlywood;">
        <h2>Register</h2>
        <div >
        <label for="name">Name</label>
        <input type="text" name="name" id="name" >
        </div>
        <div >
        <label for="email">Email</label>
        <input type="email" name="email" id="email">
        </div>
        
        <div >
            <label for="pass">Passsword</label>
        <input type="password" name="password" id="pass">
        </div>
        <div>
        <label for="pss-conf">Confirm password</label>
        <input type="password" name="confirm-pass" id="pss-conf">
        </div>
        <button type="submit" name="action" value="register">Register</button>
    
    </form>
    </section>
   
</body>
</html>