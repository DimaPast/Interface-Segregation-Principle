#include <iostream>


class TaskManager {
public:
    virtual void createTask() = 0;
    virtual void assignTask() = 0;
    virtual void completeTask() = 0;
};


class NotificationManager {
public:
    virtual void sendNotification(const std::string& message) = 0;
};


class OrderProcessor : public TaskManager, public NotificationManager {
public:

    virtual void processOrder(double totalAmount) {
        processPayment(totalAmount);
        shipOrder();

        std::cout << "Order processed successfully!\n";
        sendNotification("Your order has been processed.");
    }


    virtual void processPayment(double amount) {
        std::cout << "Processing payment of $" << amount << std::endl;

    }

    virtual void shipOrder() {
        std::cout << "Shipping order\n";

    }
};


class AdminTaskManager : public TaskManager, public NotificationManager {
public:
    void createTask() override {
        std::cout << "Admin creates a task.\n";

        sendNotification("A new task has been created.");
    }

    void assignTask() override {
        std::cout << "Admin assigns a task.\n";

        sendNotification("You've been assigned a new task.");
    }

    void completeTask() override {
        std::cout << "Admin completes a task.\n";

        sendNotification("The task has been completed.");
    }

    void sendNotification(const std::string& message) override {
        std::cout << "Sending notification: " << message << "\n";

    }
};

int main() {

    AdminTaskManager adminTaskManager;

    std::cout << "Admin Task Management:\n";
    adminTaskManager.createTask();
    adminTaskManager.assignTask();
    adminTaskManager.completeTask();

    return 0;
}
