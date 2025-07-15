# Music System in C

A feature-rich music player system implemented in C that simulates a music playlist management system with queue functionality. This project demonstrates the implementation of data structures like doubly linked lists and queues to create an efficient music player system.

## Features

- **Playlist Management**
  - Create and delete playlists
  - Add songs at specific positions
  - Delete songs from playlist
  - Display playlist contents
  - Search for specific songs

- **Playback Control**
  - Play specific songs by ID
  - Play next song
  - Play previous song
  - Queue management for song playback

- **Advanced Features**
  - Shuffle functionality with k-swap operations
  - Reverse playlist
  - Debug mode to detect cycles in playlist
  - Queue-based playback system

## Project Structure

- `main.c` - Main program file with command processing
- `music_player.h/c` - Core music player functionality
- `dll.h/c` - Doubly linked list implementation
- `queue.h/c` - Queue data structure implementation
- `sample_input1.txt`, `sample_input2.txt` - Sample input files
- `sample_output1.txt`, `sample_output2.txt` - Expected output files

## Available Commands

1. `create_playlist` - Creates a new playlist
2. `delete_playlist` - Deletes the current playlist
3. `create_music_queue` - Creates a new music queue
4. `clear_music_queue` - Clears the current music queue
5. `add_song <id> <position>` - Adds a song with given ID at specified position
6. `delete_song <id>` - Removes a song with given ID
7. `search_and_play <song_id>` - Searches and plays a specific song
8. `play_next` - Plays the next song (from queue if available, otherwise from playlist)
9. `play_previous` - Plays the previous song in the playlist
10. `insert_to_queue <id>` - Adds a song to the queue
11. `shuffle <k>` - Performs k-swap and reverse operations
12. `debug <n> <s>` - Checks for cycles in the playlist
13. `display_playlist` - Shows the current playlist contents

## How to Use

1. Compile the program:
   ```bash
   gcc -o music_player main.c music_player.c dll.c queue.c
   ```

2. Run the program:
   ```bash
   ./music_player
   ```

3. The program reads commands from the input file (default: sample_input2.txt) and executes them accordingly.

## Input File Format

The input file should contain commands in the following format:
- First line: Number of commands (n)
- Following n lines: Commands with their respective parameters

Example:
```
5
create_playlist
add_song 1 -1
add_song 2 -1
play_next
display_playlist
```

## Implementation Details

- Uses a doubly linked list for playlist management
- Implements a queue for managing song playback order
- Supports various playlist manipulation operations
- Includes debugging functionality for playlist integrity

## Error Handling

The system includes basic error handling for:
- File opening errors
- Invalid command formats
- Invalid song IDs or positions
- Memory allocation failures

## Sample Files

The project includes sample input and output files for testing:
- `sample_input1.txt` and `sample_input2.txt` contain example commands
- `sample_output1.txt` and `sample_output2.txt` show expected outputs

## Note

This is a simulation system that demonstrates the implementation of data structures and algorithms. The actual playing of music files is simulated through the `play_song()` function. 