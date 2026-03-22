while (fread(buffer, 1, 512, card) == 512)
{
    // Check for JPEG header
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        // Close previous file if open
        if (img != NULL) fclose(img);

        // Create new filename (000.jpg, 001.jpg, etc.)
        sprintf(filename, "%03i.jpg", count++);
        img = fopen(filename, "w");
    }

    // If a file is open, keep writing the blocks
    if (img != NULL)
    {
        fwrite(buffer, 1, 512, img);
    }
}
