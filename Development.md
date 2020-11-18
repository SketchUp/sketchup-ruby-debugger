# Development

## Building

### Mac

    cd Build
    xcodebuild -scheme SURubyDebugger -configuration Release

    xcodebuild -scheme SURubyDebugger -showBuildSettings | grep TARGET_BUILD_DIR

### Windows

TODO:

## Releasing

1. Update binary versions. (VS Resource Editor)
2. Build binaries for each platform.
3. Tag commit it was built from.
4. Upload binaries to GitHub Releases.
5. Update README.md to refer to new download URL and versions.
