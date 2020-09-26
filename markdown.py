class code:
    def block(code, lang):
        """Creates a code block with the given programming language for syntax highlighting."""
        return "```" + lang + "\n" + code + "\n```"

    def inline(code):
        return "`" + code + "`"


class url:
    def url(text, url):
        return "[" + text + "](" + url + ")"

    def issue(num):
        return url("GH-" + num, + "../../issues/" + num)


class sym:
    """Semanitc Symbols for GitHub rendering of Markdown files"""
    def success():
        return ":heavy_check_mark:"

    def fail():
        return ":x:"

    def wip():
        return ":construction:"

    def warn():
        return ":warning:"

    def info():
        return ":information_source:"

    def unknown():
        return ":question:"


class table:
    """Table characters"""
    def seperator():
        return " | "

    def newline():
        """Newline which works inside a single table cell"""
        return "<br>"
