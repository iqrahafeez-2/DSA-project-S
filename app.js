// Get references to buttons and output area
const loadPlaylistBtn = document.getElementById('loadPlaylistBtn');
const addSongBtn = document.getElementById('addSongBtn');
const playNextBtn = document.getElementById('playNextBtn');
const viewHistoryBtn = document.getElementById('viewHistoryBtn');
const outputArea = document.getElementById('outputArea');

// Helper function to display output
const displayOutput = (message) => {
    outputArea.textContent = message;
};

// Load playlist from the server
loadPlaylistBtn.addEventListener('click', async () => {
    try {
        const response = await fetch('/loadPlaylist');
        const data = await response.json();
        displayOutput('Playlist:\n' + data.join('\n'));
    } catch (error) {
        displayOutput('Error loading playlist: ' + error.message);
    }
});

// Add a song to the queue
addSongBtn.addEventListener('click', async () => {
    const song = prompt('Enter the song name:');
    if (!song) return;

    try {
        const response = await fetch('/enqueue', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ song }),
        });
        const data = await response.json();
        displayOutput('Added to queue: ' + data.song);
    } catch (error) {
        displayOutput('Error adding song to queue: ' + error.message);
    }
});

// Play the next song from the queue
playNextBtn.addEventListener('click', async () => {
    try {
        const response = await fetch('/dequeue');
        const data = await response.json();
        displayOutput('Now playing: ' + data.song);
    } catch (error) {
        displayOutput('Error playing next song: ' + error.message);
    }
});

// View playback history
viewHistoryBtn.addEventListener('click', async () => {
    try {
        const response = await fetch('/history');
        const data = await response.json();
        displayOutput('Playback History:\n' + data.join('\n'));
    } catch (error) {
        displayOutput('Error viewing playback history: ' + error.message);
    }
});
