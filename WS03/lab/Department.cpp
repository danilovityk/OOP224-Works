#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {



void Department::updateName(const char* newname)
{
    if(newname != NULL && strlen(newname) != 0)
    {
        if (d_departmentName != NULL)
        {
            
            delete[] d_departmentName;
            d_departmentName = NULL;
            
            
        }
        
        d_departmentName = new char [strlen(newname) + 1];
        
        
        strcpy(d_departmentName, newname);
        
    }
}





void Department::updateBudget(double change)
{
    d_budget += change;
}




bool Department::addProject(Project& newproject)
{
    bool garbage = false;
    
    double expenses = totalexpenses() + newproject.m_cost;
    
    
   
   
 
    
    if (d_budget > expenses)
    {
        
        
        if (d_numberOfProjects == 0)
        {
            d_Projects = new Project[1];
            
            d_Projects[0] = newproject;
            
            d_numberOfProjects = 1;
            
            garbage = true;
            
        }else if (d_numberOfProjects > 0)
            
        {
            Project *temp = new Project [d_numberOfProjects + 1];
            
            for (int j = 0; j < d_numberOfProjects; j++)
            {
                temp[j] = d_Projects[j];
            }
            
            temp[d_numberOfProjects] = newproject;
            
            delete[] d_Projects;
            
            d_Projects = temp;
            
            d_numberOfProjects++;
            
            garbage = true;
        }
        
        
    }
    
    
    
    return garbage;
}



void Department::createDepartment(const char* newname, Project& newproject, double change)
{
    updateName(newname);
    addProject(newproject);
    updateBudget(change);
}

Project* Department::fetchProjects() const{
    

    return d_Projects;
        
}



int Department::fetchNumProjects() const
{
    return d_numberOfProjects;
}


double Department::fetchBudget() const{
    
    return d_budget;
}



char* Department::fetchName() const{
    
    
    return d_departmentName;
    
}



double Department::totalexpenses(){
    
    double totalProjectsPrice = 0;
    
    
    d_numberOfProjects = fetchNumProjects();
    
        for(int i = 0; i < d_numberOfProjects; i++)
        {
            totalProjectsPrice += d_Projects[i].m_cost;
        }
        
    
    return totalProjectsPrice;
}



double Department::remainingBudget(){
    
    return (d_budget - totalexpenses());
}



void Department::clearDepartment()
{
    delete[] d_departmentName;
    d_departmentName = NULL;
    
    delete[] d_Projects;
    d_Projects = NULL;
    
}


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

}
