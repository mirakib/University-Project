import os
from time import sleep
import getpass


def SetUser(arg=False):

    print()

    if arg:
        print()
    else:
        print("\n[*] Critical file missing. Program need to configure.\n")

    print("+" + "-" * 23 + "+" + "\n|  Enter User details.  |" + "\n+" + "-" * 23 + "+\n")
    Name = input("Name: ")
    UserName = input("User name: ")
    Pass = getpass.getpass("Password: ")

    with open("Cache.txt", "r") as Cache:
        data = Cache.readlines()

    data[0] = "{}={}\n".format("Status", "Authen")
    data[1] = "{}={}\n".format("Name", Name)
    data[2] = "{}={}\n".format("UserName", UserName)
    data[3] = "{}={}\n".format("Password", Pass)

    with open("Cache.txt", "w") as Cache:
        for line in data:
            Cache.write(line)


def Setup():

    print("\nConfigure your data.\n")

    TotalRoom = int(input("Total room: "))

    with open("Room Status.txt", "w") as RS:
        for i in range(100, 100 + TotalRoom):
            print(str(i), "4", "A=empty", "B=empty", "C=empty", "D=empty", file=RS)

    with open("Hall Status.txt", "w") as HS:
        HS.write("Total room: {}\n".format(TotalRoom))
        HS.write("Total seats: {}\n".format(TotalRoom * 4))


def ProgramInitializer():
    msg1 = "Program Initializing"

    for char in msg1:
        print(char, end="", flush=True)
        sleep(0.050)

    for _ in range(10):
        print(".", end="", flush=True)
        sleep(0.2)

    print()

    CacheFormat = ["Status=NULL\n", "User=NULL\n", "UserName=admin\n", "Password=admin\n"]

    if os.path.exists("Cache.txt"):
        pass
    else:
        with open("Cache.txt", "w") as Cache:
            for line in CacheFormat:
                Cache.write(line)

        SetUser()

    # checking weather the file exist or not
    if os.path.exists("Room Status.txt"):
        msg2 = "\nProgram Initialized\n"

        for char in msg2:
            print(char, end="", flush=True)
            sleep(0.020)

        os.system("cls")
    else:
        Setup()


ProgramInitializer()


def authentication():
    """ Authentication function """

    print("\n[*] To access. Please log in.\n")

    GetUser = input("Username: ")
    GetPassword = getpass.getpass("Password: ")

    with open("Cache.txt", "r") as Cache:
        data = Cache.readlines()

    flag = False

    UserName = ""
    Password = ""

    if "Authen" in data[0]:
        UN = list(data[2].split("="))
        PW = list(data[3].split("="))

        UserName = UN[1].strip()
        Password = PW[1].strip()

        flag = True

    elif "NULL" in data[0]:

        UserName = "admin"
        Password = "admin"

        flag = True

    if flag:
        # always give access with default pass
        if (UserName == GetUser) and (Password == GetPassword):
            return True
        else:
            return False


# Authorizing access
AuthorizationStatus = authentication()


def Menu():

    # Menu prompt
    print("""
    +--------------------------------+
    |             MENU               |
    +--------------------------------+
    |   0 - Show Menu                |
    |   1 - Show hall status         |
    |   2 - Show room status         |
    |   3 - Assign seat to a student |
    |   4 - Empty a seat             |
    |   5 - Settings                 |
    |   6 - Exit                     |
    +--------------------------------+
    """)


def one():

    print("Hall Status:\n")

    with open("Hall Status.txt", 'r') as HS:
        print(HS.read())


def two():

    with open("Room Status.txt", "r") as RS:
        for line in RS:
            list_ = line.split()
            print("+" + "-" * 18 + "+" + "-" * 19 + "+" + "\n|", end="")
            print(" Room number:", list_[0], "|", end="")
            print(" Seat available:", list_[1], "|")
            print("+" + "-" * 18 + "+" + "-" * 19 + "+")

            # printing seat status of room
            for i in range(2, 6):
                print("   Seat: ", list_[i])

        print("\n\n")


def three():

    os.system("cls")

    print("To assign a seat, enter followings: ")

    RoomNumber = input("Room Number: ")

    with open("Room Status.txt", "r") as RS:
        data = RS.readlines()

    # getting given room data
    Room = data[int(RoomNumber) - 100].split()  # storing room data as a list
    # i.e Room = ["109", "3", "A=empty", "B=empty", "C=empty", "D=3016",]

    Space = int(Room[1])  # getting room space

    # before assign a seat in a room, it will first check room status and proceed accordingly
    if Space == 0:
        print("Room has no seat available.")

    else:
        print("Room has {} available seat.".format(Space))

        StudentId = input("Student Id: ")
        SeatNumber = input("Seat Number: ")

        if SeatNumber == "A":

            if "empty" in Room[2]:
                Room[2] = "A={}".format(StudentId)
                print("\n[+] {} is assigned on seat no {}.".format(StudentId, SeatNumber))
                Space -= 1  # room space decreases if seat assigned
            else:
                print("\n[*] Seat is already filled")

        elif SeatNumber == "B":

            if "empty" in Room[3]:
                Room[3] = "B={}".format(StudentId)
                print("\n[+] {} is assigned on seat no {}.".format(StudentId, SeatNumber))
                Space -= 1  # room space decreases if seat assigned
            else:
                print("\n[*] Seat is already filled")

        elif SeatNumber == "C":

            if "empty" in Room[4]:
                Room[4] = "C={}".format(StudentId)
                print("\n[+] {} is assigned on seat no {}.".format(StudentId, SeatNumber))
                Space -= 1  # room space decreases if seat assigned
            else:
                print("\n[*] Seat is already filled")

        elif SeatNumber == "D":

            if "empty" in Room[5]:
                Room[5] = "D={}".format(StudentId)
                print("\n[+] {} is assigned on seat no {}.".format(StudentId, SeatNumber))
                Space -= 1  # room space decreases if seat assigned
            else:
                print("\n[*] Seat is already filled")

        # building newly formatted string
        Value = ""
        for item in Room:
            Value += " " + item

        Value = Value.strip()  # trailing space removed
        Value += "\n"  # newline character added
        Value = Value.replace(Value[4], str(Space))  # Room space value replaced with decreased one

        data[int(RoomNumber) - 100] = Value  # replace item with newly built Value

        with open("Room Status.txt", "w") as TS:
            for line in data:
                TS.write(line)


def four():

    os.system("cls")

    RoomNumber = input("Enter room number: ")
    SeatNo = input("Enter seat no: ")

    with open("Room Status.txt", "r") as TS:
        data = TS.readlines()

    # getting given room data
    Room = data[int(RoomNumber) - 100].split()  # storing room data as a list
    # i.e Room = ["109", "3", "A=empty", "B=empty", "C=empty", "D=3016",]

    Space = int(Room[1])  # getting room space
    Space += 1  # room space value increased

    # building newly formatted string
    Value = ""
    for item in Room:
        if SeatNo in item:
            Value += " " + "{}=empty".format(SeatNo)
        else:
            Value += " " + item

    Value = Value.strip()  # trailing space removed
    Value += "\n"  # newline character added
    Value = Value.replace(Value[4], str(Space))  # Room space value replaced with decreased one

    data[int(RoomNumber) - 100] = Value  # replace item with newly built Value

    with open("Room Status.txt", "w") as TS:
        for line in data:
            TS.write(line)

    print("[*] {} of room {} emptied.".format(SeatNo, RoomNumber))


def ResetDefault():

    os.system("cls")

    msg = "\nprogram resetting..............\n"

    for char in msg:
        print(char, end="", flush=True)
        sleep(.15)

    CacheFormat = ["Status=NULL\n", "User=NULL\n", "UserName=admin\n", "Password=admin\n"]

    with open("Cache.txt", "w") as Cache:
        for line in CacheFormat:
            Cache.write(line)

    with open("Hall Status.txt", "r") as HS:
        data = HS.readlines()

    var = data[0].split()

    TotalRoom = int(var[2])

    with open("Room Status.txt", "w") as RS:
        for i in range(100, 100 + TotalRoom):
            print(str(i), "4", "A=empty", "B=empty", "C=empty", "D=empty", file=RS)

    msg = "[*] program reset.\n"

    for char in msg[4:]:
        print(char, end="", flush=True)
        sleep(0.15)


def settings():

    os.system("cls")

    print("""
    +---------------------------+
    |         Settings          |
    +---------------------------+
    |   1. Reset Default        |
    |   2. Set User             |
    |   3. Menu                 |
    +---------------------------+
    """)

    while True:
        cmd = input("\n[ Choose setting option ] ")

        if cmd == "1":
            ResetDefault()
        elif cmd == "2":
            SetUser(True)
        elif cmd == "3":
            console()
        else:
            print("\n[*] Invalid input")


def console():
    Menu()

    while True:
        cmd = input("\n[ Press valid command ] ")

        if cmd == "0":
            os.system("cls")
            Menu()
        elif cmd == "1":
            os.system("cls")
            one()
        elif cmd == "2":
            os.system("cls")
            two()
        elif cmd == "3":
            os.system("cls")
            three()
        elif cmd == "4":
            os.system("cls")
            four()
        elif cmd == "5":
            os.system("cls")
            settings()
        elif cmd == "6":
            os.system("cls")
            exit()
        else:
            os.system("cls")
            print("\n[*] Wrong command. Try pressing 0 for available operation.")


# give access to console if authentication is successful
if AuthorizationStatus:
    console()
else:
    print("\n[*] Wrong Username or Password")


def ProgramWeaknesses():
    print("ProgramWeaknesses")

    # Current weaknesses
    """
    > Room number cannot exceed more than three char
    > Can only work with three seats per room
    """

    # Need to debug
    """
        @ input validation
            > seat input
            > StudentId input
            > room number input

        @ error validation
            > the student already has a seat cannot be assigned twice
    """
