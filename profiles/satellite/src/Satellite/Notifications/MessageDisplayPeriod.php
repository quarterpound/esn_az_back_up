<?php
/**
 * Created by PhpStorm.
 * User: marco
 * Date: 1/28/19
 * Time: 1:27 AM
 */

namespace ESN\Satellite\Notifications;

class MessageDisplayPeriod implements \JsonSerializable {

  /** @var \DateObject */
  private $from;

  /** @var \DateObject */
  private $to;

  public function __construct() {
    $this->from = new \DateObject(0);
    $this->to = new \DateObject('2100-01-01');
  }

  /**
   * Specify data which should be serialized to JSON
   *
   * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
   * @return mixed data which can be serialized by <b>json_encode</b>,
   * which is a value of any type other than a resource.
   * @since 5.4.0
   */
  public function jsonSerialize() {
    $data = new \stdClass();
    $data->from = $this->from->getTimestamp();
    $data->to = $this->to->getTimestamp();
    return $data;
  }

  /**
   * @param string $value
   */
  public function setFrom($value) {
    $this->from = is_string($value)
    ? new \DateObject($value)
    : new \DateObject($value);
  }

  /**
   * @param string $value
   */
  public function setTo($value) {
    $this->to = is_string($value)
    ? new \DateObject($value)
    : new \DateObject($value);
  }

  public function isValid() {
    $today = new \DateObject('today');
    return $this->from <= $today && $this->to >= $today;
  }

  /**
   * @return \DateObject
   */
  public function getFrom() {
    return $this->from;
  }

  /**
   * @return \DateObject
   */
  public function getTo() {
    return $this->to;
  }
}
