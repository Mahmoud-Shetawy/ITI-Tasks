import {addUser , allUser, updateUser , oneUser , deleteUser} from './../controller/user.controller.js'
import { Router } from 'express'
// import app from './../index.js'
const router = Router()


router.get('/' , allUser)
router.post('/addUser' , addUser)
router.get('/user/:id' , oneUser)
router.delete('/user/:id' , deleteUser)
router.put('/user/:id', updateUser);


export default router 