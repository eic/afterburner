import os
import sys

# What is abconv path to test?
# environment variable TEST_ABCONV_EXE could be used for that
test_dir_path = os.path.dirname(os.path.realpath(__file__))
abconv_path = os.path.join(test_dir_path, "..", "cpp", "cmake-build-debug", "abconv", "abconv")
if "TEST_ABCONV_EXE" in os.environ:
    abconv_path = os.environ.get("TEST_ABCONV_EXE")


def test_system_echo(capfd):
    """Test that abconv test will work"""
    print(f"abconv_path={abconv_path}")
    result = os.system(f'{abconv_path} --help')
    captured = capfd.readouterr()
    assert "Usage" in captured.out
    assert result == 0
