from django.shortcuts import HttpResponse, render

# def hello(request):
#    text = """<h1>welcome to my app !</h1>"""
#    return HttpResponse(text)



def hello(request):
   
    students = [
        {"name": "Adel", "age": 21, "course": "Math", "grade": "A"},
        {"name": "Ramadan", "age": 22, "course": "Physics", "grade": "B"},
        {"name": "Saber", "age": 20, "course": "Chemistry", "grade": "C"},
        {"name": "Elabmby", "age": 23, "course": "Biology", "grade": "A"},
    ]

    # Pass the data to the template
    return render(request, "student/index.html", {"students": students})