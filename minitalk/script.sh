#!/bin/bash

# Path to the Minitalk client executable
CLIENT="./client"

# The message to send and the process ID (replace with appropriate values)
MESSAGE="ravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo.ravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae dui. Nam ac sem faucibus, interdum nunc at, dapibus ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae dui. Nam ac sem faucibus, interdum nunc at, dapibus ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae dui. Nam ac sem faucibus, interdum nunc at, dapibus ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae dui. Nam ac sem faucibus, interdum nunc at, dapibus ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae dui. Nam ac sem faucibus, interdum nunc at, dapibus ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae dui. Nam ac sem faucibus, interdum nunc at, dapibus ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae duffinibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae dui. Nam ac sem faucibus, interdum nunc at, dapibus ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendiss"
PID="6413" # Replace with the actual process ID of the server

# Infinite loop to run the client
while true; do
    echo "Running client with message: '$MESSAGE' to process ID: $PID"
    $CLIENT $PID "$MESSAGE"
    
    # Add a sleep delay if needed to avoid overwhelming the system
    sleep 1
done
