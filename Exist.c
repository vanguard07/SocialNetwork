void Exist(char username[20])
{
        system("COLOR 0A");
        int n;
        printf("\t\t\t1.Add Friends\n\t\t\t2.Send Message\n\t\t\t3.Check Requests\n\t\t\t4.Friends\n\t\t\t5.Logout\n\t\t\t");
        printf("Enter choice: ");
        scanf("%d", &n);
        switch(n)
            {
            case 1 :	system("cls");
                        Add(username);
                        break;
            case 2 :	system("cls");
                        Search(username);
                        break;
            case 3 :	system("cls");
                        Requests(username);
                        break;
            case 4 :    List(username);
                        break;
            case 5 :  	system("cls");
                        main();
                        break;
            }
}
